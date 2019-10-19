#ifndef SET_T
#define SET_T

#include "set_visitor.h"
#include <map>
#include <string>

class Set {
    public:
        class SetIterator {
            public:
                SetIterator(Set* set): _set(set) {
                }

                void first() {
                    _it = _set->_children.begin();
                }

                Set currentItem() {
                    if (isDone()) {
                        throw std::string("no current item");
                    }

                    return _it->second;
                }

                void next() {
                    if (isDone()) {
                        throw std::string("moving past the end");
                    }
                    _it++;
                }

                bool isDone() {
                    return _it == _set->_children.end();
                }

            private:
                Set* _set;
                std::map<std::string, Set>::iterator _it;
        };

        Set() : _children(std::map<std::string, Set>{}), _setSeq(0), _pureNumValue(nullptr) {
        }

        bool isPureNum() const {
            return this->_children.size() == 0 && this->_pureNumValue != nullptr;
        }

        bool isEmpty() const {
            return this->_children.size() == 0 && this->_pureNumValue == nullptr;
        }

        void add(int number) {
            std::string key = "num" + std::to_string(this->_setSeq);

            Set pureNumSet;
            pureNumSet._pureNumValue = new int(number);
            this->_children[key] = pureNumSet;

            this->_setSeq += 1;
        }

        void add(Set childSet) {
            std::string key = "set" + std::to_string(this->_setSeq);

            this->_children[key] = childSet;

            this->_setSeq += 1;
        }

        std::string toString() const {
            std::map<std::string, Set>::const_iterator it;
            std::string result = "{";

            if (this->isEmpty()) {
                return "{}";
            }

            for (it = this->_children.begin(); it != this->_children.end(); it++) {
                if (it->second.isEmpty()) {
                    result += "{}";
                } else if (!it->second.isEmpty() && it->second.isPureNum()) {
                    result += std::to_string(*it->second._pureNumValue);
                } else {
                    result += it->second.toString();
                }

                if (it->first != this->_children.rbegin()->first) {
                    result += ",";
                } else {
                    result += "}";
                }
            }

            return result;
        }

        void accept(SetVisitor* visitor) {
            visitor->visitSet(this);
        }

        SetIterator* createItr() {
            return new Set::SetIterator(this);
        }

        int getPureNum() const {
            return *this->_pureNumValue;
        }

    private:
        std::map<std::string, Set> _children;
        int* _pureNumValue;
        int _setSeq;
};

#endif