# prosise-mfc2e

Revisited C++ source code for Jeff Prosise's Programming Windows with MFC 2nd Edition ISBN-10 1572316950

In conjunction with [petzold-pw5e](https://github.com/definedrisk/petzold-pw5e).

The primary aim is to ensure the example projects **compile** in both *release* and *debug* configurations. I may add further comments on runtime issues at a later date.

The orginal projects are copied from CD-ROM (zipped copy inlcuded within this repository) with only necessary changes (if required) to ensure they compile. The `.dsw` workspace has been opened in VS2019 and saved as a `.sln` solution. This is likely to mean that during compilation and running there are warnings messages. I have attempted to remove all error messages with minimal changes. This process can only been perfromed using VS2019 (see [C++ features deprecated in Visual Studio](https://docs.microsoft.com/en-us/cpp/porting/features-deprecated-in-visual-studio?view=msvc-170)).

Subsequently the solution can be opened in VS2022 and *Retarget Project* selected to *Upgrade Platform Toolset to v143 and Windows SDK to Version 10.0 (latest version)* if required. VS2022 has been installed with *C++ v14.29 (16.11) ATL for v142 build tools (x86 & x64)* and *C++ v14.29 (16.11) MFC for v142 build tools (x86 & x64)*, so this option does not appear by default.  See [Windows SDK and emulator archive](https://developer.microsoft.com/en-us/windows/downloads/sdk-archive/) for Windows SDK verions and release notes.

See also [Microsoft Docs : Get Started with Win32 and C++](https://docs.microsoft.com/en-us/windows/win32/learnwin32/learn-to-program-for-windows) and [Microsoft Docs : MFC Desktop Applications](https://docs.microsoft.com/en-us/cpp/mfc/mfc-desktop-applications?view=msvc-170) for further reading.

Generally I create extra folders where name is appended with `_19` or `_22` to include any additional changes that I add which attempt to remove warning messages. These changes should be summarised in text for each project below.

Unless otherwise stated all projects require:

* Debug Configuration
    * C/C++ -> General -> Debug Information Format changed from /ZI to /Zi
    * C/C++ -> Code Generation -> Enable Minimal Rebuild change from /Gm to /Gm-

* Delete the `.\Backup` folder and `UpgradeLog.htm` file.

## Ch2

### Accel and Ruler

* Add missing type definition `int` in `for` loops.

## Ch3

### VisualKB

* TCHAR cast required.

## Ch8

### DlgCalc

* TCHAR cast required.



... *work in progress* ... 