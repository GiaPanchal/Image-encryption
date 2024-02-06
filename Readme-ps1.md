# PS1: LFSR / PhotoMagic

## Contact
Name: Gia Panchal

Section: 202

Time to Complete: 4 hours


## Description
Explain what the project does.

ps1a: This project simulates a Linear Feedback Shift Register(LFSR) that takes a sequence of bits and shifts the bit position to the left by one and replaces the last empty bit by the result of XOR from bits previously at the tap positions in the register.

ps1b: This part of project uses the LFSR made in ps1a to encrypt images with the use of the SFML API. This can be done by extracting each of the RBG components from each pixel of the input image and replacing that with a new random color.

### Features
Describe the representation you used and why you did things that way.

ps1a: I used a string representation to make manipulation of shifting bit positions easier. It also allowed getting values at tap positions and converting the values to integers to get a result through XOR operation.

ps1b: I extracted each RBG component from each of the pixels than used it to XOR with the binary input key to recive a random color to replace the pixel.

### Issues
What doesn't work.  Be honest.  You might be penalized if you claim something works and it doesn't.

I believe everything works.

### Tests
Describe what is being tested in your Boost unit tests.

ps1a: I have 4 added tests. The output operator which prints the current state of the seed before and after some manipulation. A mix of steps and generate, tests the step function 3 times then tests the generate function once. testLargeNumberofSteps uses a for loop to call step() 50 times. A test that calls generate(23) to test generate with a result value.  

ps1b: Added 1 more test that tests the seed left shifting 24 times after the transform function (since generate(8) is called 3 times in the transform function)

### Extra Credit
Anything special you did. This is required to earn bonus points.

ps1b: Photomagic command line can now take a 16 bits long alphanumeric key instead of binary and still be able to encrypt and decrypt the image. This is achived by the main checking if the key includes any alphanumeric values and if so it calls the convertToBinary function that takes the key as its argument. In the convertToBinary function the alphanumeric value is converted to int, which potentially each of the characters of the key to its ascii values. Then these ascii values are added together and converted to binary. This function than returns the string of binary values.

## Acknowledgements
List all sources of help including the instructor or TAs, classmates, and web pages.

ps1a:
https://www.geeksforgeeks.org/program-binary-decimal-conversion/
https://www.boost.org/doc/libs/1_53_0/libs/test/doc/html/utf/tutorials.html
https://xor.pw/
Discussed with Owen O'brien, Wilson Van

ps1b:
https://www.sfml-dev.org/documentation/2.6.1/group__graphics.php
https://www.sfml-dev.org/documentation/2.6.1/classsf_1_1Image.php
https://www.sfml-dev.org/documentation/2.6.1/classsf_1_1Color.php
Provided pixels.cpp file
Discussed with Owen O'brien, Wilson Van