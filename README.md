### This is a repository for building a NuGet package of log4cpp.

The log4cpp project is located here: https://sourceforge.net/p/log4cpp/


## Building instructions

0. Prerequisites: vc142 toolset (installed with MS Visual Studio 2019 or as part of associated build tools); `cmake`, `MSBuild` and `nuget` on the PATH
1. Clone the repository
2. Run `BuildNugetPackage.cmd`
3. Test the resulting package by following the instructions in the README in the _./nuget-sample_ directory.

