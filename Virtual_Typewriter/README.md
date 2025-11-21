                                                    #🖨️ C++ Virtual Typewriter Automation

This project is a Windows-based automated typing system built in C++.
It simulates human-like typing by moving the mouse cursor to a specific position and generating real keystrokes — similar to tools like AutoHotKey or PyAutoGUI, but fully implemented using the Win32 API.


🚀 Features

✔️ Types any given string automatically


✔️ Simulates real keyboard input (Shift, symbols, uppercase, lowercase)


✔️ Moves mouse cursor to a specified screen position before typing


✔️ Adjustable typing delay for natural effect


✔️ Supports letters, numbers, symbols, and whitespace




🧠 How It Works


This project uses:


SetCursorPos() → Move cursor to desired coordinates


mouse_event() → Simulate mouse click on a field


keybd_event() → Generate key press events


Win32 Virtual-Key Codes mapping for characters


🎯 Why I Built It


I built this project to explore:


->Low-level input simulation


->Keyboard event handling


->Virtual-Key codes and character mapping


->Automation and human-text simulation


->How operating systems interpret synthetic input


->It started as a simple idea — “Can I make C++ type for me?”


But it turned into a complete automation tool capable of typing full sentences with accuracy and timing control.


The logic mimics how a real user types:


holding SHIFT when needed, releasing keys after press, and inserting delays.
