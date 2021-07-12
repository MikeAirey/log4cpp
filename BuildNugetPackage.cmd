@echo off

@echo Building Debug and Release configurations of log4cpp and producing NuGet package for Win32 platform.

MSBuild BuildNugetPackage.vcxproj /p:Platform=Win32 /p:Configuration=Debug
MSBuild BuildNugetPackage.vcxproj /p:Platform=Win32 /p:Configuration=Release
pushd nuget
nuget pack
popd
