# Pattern Oriented Software Design
#### Fall, 2019
#### Dept. of Computer Science and Information Engineering
#### Taipei Tech

#### Homework 8

# Purpose of the homework
####  Implement Observer Pattern.
####  Implement the text editor with following feature.
   * Show folder structure with file size.
   * Modify file name and save the change.
   * Show the file content.
   * Modify file content and save the change.

Write down which your development enviroment is in `README.md`, MAC, LINUX or Ubuntu bash in win10.

If you don't record your development enviroment then we will run your program in Ubuntu bash in win10. 

And if it cannot run in TA's machine, you will not get any grade.

# Requirements
 1. Display the folder structures using wxwidgets.

 ![main page](/image/mainpage.png)

 2. **Feature 1: Show folder structure with file size.**

 Use the command to choose which folder structure should represent in wxwidgets.

 Type following command:

 ![command](/image/command.PNG)

 Representation:

 ![main page](/image/mainpage.png)

 Demo:
 [Feature1](https://drive.google.com/file/d/1HJukDp3vXKt0IG05xKubMKE-XEyXnKua/view?usp=sharing)

 `Tips: Use the wxTreeCtrl to implement this feature.`

 3. **Feature 2: Modify file name and save the change.**

 Double click the label to enter the edit mode.  After renaming the file, Show the dialog when pressing the Enter. Click yes to save the change, otherwise, discard save.

 You should not be allowed to edit the part of size in the label.

 Double click:

 ![editTreeView](/image/editTreeView.png)

 Rename and press Enter:

 ![Show dialog](/image/editTreeViewDialog.png)

 Save the change:


 ![Save the change](/image/SaveTheChangeInTreeView.png)

 Edit size:

 ![Edit size](/image/editSize.png)

 Press `Enter` after editing size:

 ![Press `Enter` after editing size](/image/pressEnterAfterEditSize.png)


 Demo:
 [Feature2](https://drive.google.com/file/d/1zJ2_eUUdu8mF-y0UMB2YE2a90CcmYhzz/view?usp=sharing)

 `Note: Use Observer pattern.`

 4. **Feature 3: Show the file content**

 Click the Node in tree view on the left of the application windows. And show the corresponding text content on right of the application windows. if the node can not show the text content. please show the default content on the right of the application windows.

 default content:
 
 binary file & link: "The file is not displayed in the editor because it uses an unsupported text encoding.".

 folder: do not show anything.

 Click the node which can show the text content.

 ![textContent page](/image/editViewShowTextfile.png)

 Click the node which can not show the text content.

 ![binaryContent page](/image/editViewShowBinaryfileDefaultValue.png)

 Demo:
 [Feature3](https://drive.google.com/file/d/1FhPhdp2hPRkcRN5gqjWMEMui4vtbp9JY/view?usp=sharing)

 `Tips: Use the wxTextCtrl to implement this feature.`

 5. **Feature 4: Modify file content and save the change**

 Modity the text content and click the save button or press `ctrl+s` key to save the change. Show the dialog when you click save button or press `ctrl+s` key. Click yes to save the change, otherwise, discard save.

 Edit the content and click the save button or press `ctrl+s` key:

 ![Show dialog](/image/editEditViewDialog.png)

 Save the change:

 ![Save the change](/image/SaveEditView.png)

 After change the file content the size of the file will change, and you should alse update the size in the label!

 Demo:
 [Feature4](https://drive.google.com/file/d/11sYX52X-NHpEnJR7U2_uvKJG5rqMBJXp/view?usp=sharing)

 `Note: Use Observer pattern.`

 6. Write the corresponding makefile to generate executable file which named `hw8` in bin folder.


# Grading rubrics
Each feature is 25 points.

# Deadline
11:59 p.m. 4 Jan  2020

# Note
Make sure your wxwidgets is installed and working correctly.
Then you can push to Gitlab.

Write the corresponding makefile to generate executable file which named `hw8` in bin folder.

We will `make` in TA's machine to generate `hw8` and you should have the following file structure.


#### File structure:

```
- bin
- obj
- src
- test
makefile
README.md
```