# DriverBase

This is a base (or template if you will) for a Kernel Mode Driver using Microsoft's __Kernel Mode Driver Framework__, a
framework used to build Kernel drivers on Windows.

The project is prepared to work on any Windows version, if you find the correct winver and modify the winver argument
given to the `wdk_add_driver` CMake function from the amazing [`FindWDK
project`](https://github.com/SergiusTheBest/FindWDK), which made this 10x less painful.

If you don't know, or just can't be asked to research how to modify this value with a correct one, refer
to [this page on MSDN](https://learn.microsoft.com/en-us/cpp/porting/modifying-winver-and-win32-winnt).

For obvious reasons, when working on Kernel Mode, the standard library is not included.

### Dependencies:

- [FindWDK](https://github.com/SergiusTheBest/FindWDK) [Used for basic CMake]
- [obfusheader.h](https://github.com/ac3ss0r/obfusheader.h) [Used for compile-time obfuscation]