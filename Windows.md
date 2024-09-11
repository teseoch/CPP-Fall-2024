# Windows

The easiest way to run the code on Windows is to install [Visual Studio](https://www.visualstudio.com/).

When you install it, be sure to install `Desktop development with C++` and select all optional features.

![components](img/components.png)

## Installation

If you did not install the `Desktop development with C++`, open Visual Studio and select `Continue without code →`.

![open](img/open.png)

This will open Visual Studio. Select the `Tools` menu and open `Get Tools and Features...`.

![tools](img/tools.png)

This will open a menu similar to that when you first install it. Select `Desktop development with C++` (and select all optional features). Then confirm by pressing `Modify`.

![components](img/components.png)

This will take a while (depending on your network).

## Running the code

When you open Visual Studio, select `Create a new project`.

![project](img/project.png)

This will open a new window where you select which project. If everything is installed correctly, you should have `Console App` in the menu and click next. If not, check [Installation](installation).

![project type](img/ptype.png)

The next window lets you choose the path and project name. Choose something that makes sense to you and press `create`.

![paths](img/paths.png)

Finally, you should have a `C++` file open in the middle with some sample code.

![c++](img/cpp.png)

To **save, compile, and run** the code, press the play button.

![Run](img/play.png)

After compilation, a terminal should pop up with the program's output. The terminal also contains other stuff — look at the first line!

![Output](img/out.png)


## Running the class Examples

To run any other code, copy-paste the code over the cpp file.

Alternatively, you can drag and drop one of the cpp files into the `Source Files` project's directory.

![Drag and drop](img/drag.png)

By doing so, you should have your new file inside (you might need to expand the folder in Visual Studio)

![New file](img/file.png)

By pressing play, you will get an error since there are two files containing a `main`.

![Error](img/error.png)

In general, it is helpful to see the error panel; if you do not have it, you can open `View` and select `Error List`.

![Error panel](img/oerror.png)

To fix the error, right-click on the file you want to skip (in our case, `ConsoleApplication1.cpp`) and select `Exclude From Project`. This will exclude the file from the project but not delete it.

![Exclude](img/exclude.png)

If you want to add back an excluded project, right-click on the `Source Files` directory and select `Add > Existing Item...`.

![Add back](img/add.png)

This will open a menu where you can select the file you want to add.

![Add file](img/addfile.png)
