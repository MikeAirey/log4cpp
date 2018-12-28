## Log4cpp NuGet package sample app ##

### Important note ###
This sample app is designed to consume the log4cpp NuGet package produced by `BuildNugetPackage.cmd`. Once the package is built, you'll need to install it to this app via the package manager console.

1. Open NugetSample.sln with Visual Studio
1. Open the Package Manager Console window
1. Run this command: `install-package log4cpp -source ..\nuget\`
1. Build and run the app
1. log4cpp should write some log output to `NugetSample.log` in this directory

Don't commit any changes produced by the steps above. Since the package was installed directly from the local filesystem without a package source defined, Visual Studio won't be able to restore the package from the `.vcxproj` and `packages.config` alone.
