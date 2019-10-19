#ifndef TERMINAL_H
#define TERMINAL_H
#include <iostream>
using namespace std;
#include "triangle.h"
#include "circular_sector.h"
#include "ellipse.h"
#include "sort.h"
#include "shape.h"
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include <iterator>
#include <iomanip>
#include <regex>
class Terminal
{
public:
    // you can use regular expression to get useful token from "Input string"
    Terminal(string instruction): _instruction(instruction)
    {
      std::vector<string>* _strVec=new vector<string>(0);
      if(!isIncompelet(instruction)){
        _strVec=split(instruction,')');
        string *m;
        std::vector<string>::iterator it;
        it=_strVec->begin();
        check(it,_strVec);
        it=rmSpace(it,_strVec);
        it=filterString(it,_strVec,this->_mark,sizeof(_mark)/sizeof(*_mark),this->_shapeName,sizeof(_shapeName)/sizeof(*_shapeName));
        it=checkFormat(it,_strVec);
        checkMode(_strVec);
        _shapeVec= analysis(it,_strVec);
        _shapeVec = sortShape(_shapeVec,getFeatur(_mode[1]),getOrder(_mode[2]));
        // ShowList(_strVec);
      }else _isThrow=true;

    }
    std::vector<string>::iterator check(std::vector<string>::iterator it,std::vector<string>* vec){
      char c[3]={'T','E','C'};
      for(it=vec->begin();it!=vec->end();it++){
        for(int n=0;n<3;n++){
          if((*it).find(c[n])!=std::string::npos){
            int i=(*it).find(c[n]);
            if((*it)[i-1]==' '){
              (*it).erase(0,i);
            }
          }
        }
      }



    }

    bool isIncompelet(string instruction){//正確回傳0  錯誤回傳1
        for(string s:_modeFeature){
          if(instruction.find(s) != std::string::npos){
            for(string s1:_modeOrder){
              if(instruction.find(s1) !=std::string::npos ){
                return false;
              }
            }
          }
        }

      return true;
    }
    string getOrder(int mode){
      if(_mode[2]==0) return NULL;
      return _modeOrder[_mode[2]-1];

    }
    string getFeatur(int mode){
      if(_mode[1]==0) return NULL;
      return _modeFeature[_mode[1]-1];
    }

    std::vector<Shape*>* sortShape(std::vector<Shape*>* shapeVec,string featur,string order){
      Sort sort(shapeVec);
      if(order=="inc"){
        AscendingComparison inc(featur);
        std::sort(shapeVec->begin(),shapeVec->end(),inc);
      }
      else if(order=="dec"){
        DescendingComparison dec(featur);
        std::sort(shapeVec->begin(),shapeVec->end(),dec);
      }
      return shapeVec;
    }
    std::vector<Shape*>* analysis(std::vector<string>::iterator it,std::vector<string>* vec){
      std::vector<Shape*>* shapeVec=new vector<Shape*>(0);
      std::vector<Shape*>::iterator itShape=shapeVec->begin();
      shapeVec->clear();
        for(it=vec->begin();it!=vec->end();it++){
          string className=getClassName(*it);
          std::vector<int> numVec=getParameter(*it);
          std::vector<int>::iterator itNum=numVec.begin();
          if(className=="Triangle"){
            Triangle *tp;
            try{
              tp=new Triangle(*itNum,*(itNum+1),*(itNum+2),*(itNum+3),*(itNum+4),*(itNum+5));
            }catch(std::string *caught){
              continue;
            }
            shapeVec->push_back(tp);
          }
          else if(className=="Ellipse"){
            shapeVec->push_back(new Ellipse(*itNum,*(itNum+1)));
          }
          else if(className=="CircularSector"){
              shapeVec->push_back(new CircularSector(*itNum,*(itNum+1)));
          }

        }

      return shapeVec;

    }
    string getClassName(string str){
          std::smatch m;
          std::regex e ("\\(");
          std::regex_search ( str, m, e );
      return m.prefix().str();
    }
    std::vector<int> getParameter(string str){//讀取參數 回傳std::vector<int>;
      vector<int> number(0);
      int i;
      string stemp="";
      for(i=str.find('(')+1;i<str.size();i++){
        if(str[i]==',' || str[i]==')'){
          number.push_back(strToInt(stemp));
          stemp="";
        }
        else stemp+=str[i];
      }
      return number;
    }
    int strToInt(string strVal){
      int val;
      istringstream is(strVal);
      is>>val;
      return val;
    }

    void checkMode(std::vector<string>* vec){
        std::vector<string>::iterator it=vec->end()-1;
        int i=0;
        for(i=0;i<3;i++){//判斷Feature
          regex pattern(_modeFeature[i]);
          if(regex_search(*it,pattern)){
            _mode[1]=i+1;
            break;
          }
        }
        if(i==3){
          _isThrow=true;
        }

        i=0;
        for(i=0;i<2;i++){//判斷Order
          regex pattern(_modeOrder[i]);
          if(regex_search(*it,pattern)){
            _mode[2]=i+1;
            break;
          }
        }
        if(i==2){
          _isThrow=true;
        }

        // showMode();
    }
    void showMode(){
      cout<<"Featur:"<<_mode[1]<<endl;
      cout<<"Order:"<<_mode[2]<<endl;
    }
    std::vector<string>::iterator checkFormat(std::vector<string>::iterator it,std::vector<string>* vec){
      bool run=false;
      for(it=vec->begin();it!=vec->end()-1;){
        for(int i=0;i<3;i++){
            regex pattern(_format[i]);
            if(regex_match(*it, pattern)){
                run=true;
                break;
            }
        }
        if(run){
          run=false;
          it++;
        }else{
          it=vec->erase(it);
        }
      }
      return it=vec->begin();
    }

    std::vector<string>::iterator rmSpace(std::vector<string>::iterator it,std::vector<string>* vec){//remove additional space
      string temp="";
        for(it=vec->begin();it!=vec->end()-1;it++){
          for(char c:(*it)){
            if(c==' ')continue ;
            else temp+=c;
          }
          *it=temp;
          temp="";
        }
        return it=vec->begin();
    }

    std::vector<string>::iterator filterString(std::vector<string>::iterator it ,std::vector<string>* vec,char mark[],int count1,string name[],int count2){//有特殊字元則

      for(it=vec->begin();it!=vec->end()-1;){
        if(isMark(*it,mark,count1)){
          it=vec->erase(it);
        }
        else if(isWrongName(*it,name,count2)){
          it=vec->erase(it);
        }
        else{
            it++;
        }
      }
      return it=vec->begin();
    }

    bool isMark(string str,char mark[],int count){
      int i=0;
      while(!(str.find(mark[i])!= std::string::npos)){
        if(i==count)break;
        i++;
      }
      if(i<count){
        return 1;
      }
      else{
        return 0;
      }
    }

    bool isWrongName(string str,string name[],int count){
      std::smatch m;
      std::regex e ("\\(");
      std::regex_search ( str, m, e );
      str=m.prefix();
      int i=0;
    for(i=0;i<count;i++){
      regex pattern(_shapeName[i]);
      if(regex_match(str,pattern))
        break;
      }
      if(i==count){
        return 1;
      }
      else{
        return 0;
      }
    }


    std::vector<string>* split(string instruction,char delimiter){//利用delimiter切割字串
      std::vector<string>* strVec=new vector<string>(0);
      string str;
      strVec->clear();
      while(_index < instruction.length()){
        while(instruction[_index] != delimiter && _index < instruction.length()){
          str+=instruction[_index++];
        }
        str+=instruction[_index++];
        strVec->push_back(str);
        str="";

      }
      return strVec;
    }

    string showResult(){
         // return result For example: [XXX, XXX, XXX]
         if(_isThrow) throw string("Unuseful User Input!");

         string result="[";
         for (std::vector<Shape*>::iterator it = _shapeVec->begin() ; it != _shapeVec->end(); ++it){
           switch (_mode[1]) {
             case 1:
                result+=to_string((*it)->area());
                break;
             case 2:
                result+=to_string((*it)->perimeter());
                break;
             case 3:
                result+=to_string((*it)->sumOfSquares());
                break;
           }
           if(*it != *(_shapeVec->end()-1) )
            result+=", ";
         }
         return result+="]";
    }
    string removeAddtionZero(string value){

      for(int i=value.size()-1;i > -1;i--){
        if(value[i]=='0') value.erase(i,1);
        else break;
      }
      return value;

    }
    void ShowList(std::vector<string>* vec){
      for (std::vector<string>::iterator it = vec->begin() ; it != vec->end(); ++it)
        std::cout <<(*it)<<endl;
    }
private:
    string _instruction;
    bool _run=true;
    int _index=0;
    int _count=0;
    std::vector<Shape*>* _shapeVec;

    int _mode[3]={0};//_mode[0]=count,_mode[1]= 0:error     mode[2]= 0:error
                                            // 1:area               1:ascending
                                            // 2:perimeter          2:descending
                                            // 3:sumOfSquares
    bool _isThrow=false;
    string _modeFeature[3]={"area","perimeter","sumOfSquares"};
    string _modeOrder[2]={"inc","dec"};
    char _mark[11]={'!','@','#','$','%','^','&','*','+','>','<'};
    string _shapeName[3]={"^Triangle$","^CircularSector$","^Ellipse$"};
    string _format[3]={"^(Triangle)(\\(-?\\d{1,},-?\\d{1,},-?\\d{1,},-?\\d{1,},-?\\d{1,},-?\\d{1,}\\))$",
                        "^(CircularSector)(\\(-?\\d{1,},-?\\d{1,}\\))$",
                        "^(Ellipse)(\\(-?\\d{1,},-?\\d{1,}\\))$"};
};
#endif
