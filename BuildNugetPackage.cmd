@echo off

REM TODO explicitly reference the correct version of MSBuild, or detect it at runtime, or something.

@echo Building Debug and Release configurations of log4cpp for Win32 platform...

MSBuild BuildNugetPackage.vcxproj /p:Platform=Win32 /p:Configuration=Debug
MSBuild BuildNugetPackage.vcxproj /p:Platform=Win32 /p:Configuration=Release

@echo Building Debug and Release configurations of log4cpp x64 platform...

MSBuild BuildNugetPackage.vcxproj /p:Platform=x64 /p:Configuration=Debug
MSBuild BuildNugetPackage.vcxproj /p:Platform=x64 /p:Configuration=Release

@echo Producing NuGet package...

pushd nuget
nuget pack
popd
