# PS1: LFSR / PhotoMagic

## Contact
Name: Gia Panchal

Section: 202

Time to Complete: 4 hours


## Description
This project simulates a Linear Feedback Shift Register(LFSR) that takes a sequence of bits and shifts the bit position to the left by one and replaces the last empty bit by the result of XOR from bits previously at the tap positions in the register.
Uses the LFSR to encrypt images with the use of the SFML API. This can be done by extracting each of the RBG components from each pixel of the input image and replacing that with a new random color.

### Features
I used a string representation to make manipulation of shifting bit positions easier. It also allowed getting values at tap positions and converting the values to integers to get a result through the XOR operation.
I extracted each RBG component from each of the pixels and then used it to XOR with the binary input key to receive a random color to replace the pixel.

### Issues


### Tests
I have 4 added tests. The output operator prints the current state of the seed before and after some manipulation. A mix of steps and generate tests the step function 3 times then tests the generate function once. testLargeNumberofSteps uses a for loop to call step() 50 times. A test that calls generate(23) to test generate with a result value.  

Added 1 more test that tests the seed left shifting 24 times after the transform function (since generate(8) is called 3 times in the transform function)

### Addition
Photomagic command line can now take a 16-bit long alphanumeric key instead of binary and still be able to encrypt and decrypt the image. This is achieved by the main checking if the key includes any alphanumeric values; if so, it calls the convertToBinary function that takes the key as its argument. In the convertToBinary function, the alphanumeric value is converted to int, which potentially each of the characters of the key to its ASCII values. Then these ascii values are added together and converted to binary. This function then returns the string of binary values.

## Acknowledgements
https://www.geeksforgeeks.org/program-binary-decimal-conversion/
https://www.boost.org/doc/libs/1_53_0/libs/test/doc/html/utf/tutorials.html
https://xor.pw/
https://www.sfml-dev.org/documentation/2.6.1/group__graphics.php
https://www.sfml-dev.org/documentation/2.6.1/classsf_1_1Image.php
https://www.sfml-dev.org/documentation/2.6.1/classsf_1_1Color.php
