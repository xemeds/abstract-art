#  Abstract Art Generator

A simple abstract art generator.

# How it works

The options for the upper and lower bound of the amount of dots on the image, as well as the upper and lower bound for the dots radiuses are given. Using these upper and lower bounds, random amount of dots with random radiuses and random colors are generated on random positions on the image.

# Build & Run

You will need a standards-compliant C compiler, the standard C library with header files, and make. On Debian GNU/Linux and derivatives, you can install these with

	$ apt install build-essential

After that clone the repository and cd into it

	$ git clone https://github.com/xemeds/abstract-art.git

	$ cd abstract-art

Build and run with

	$ make

	$ ./abstract

# References

STB Image Library: [https://github.com/nothings/stb](https://github.com/nothings/stb)

# License

This project is under the [MIT](https://github.com/xemeds/abstract-art/blob/main/LICENSE) license.
