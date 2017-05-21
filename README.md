Omron D6T-44L-06 test application
=================================

Testing the sensor with openFrameworks on the Raspberry Pi. This should display a 4x4 grid with colored rectangles.

I used I2C C functions by [Scott Ellis](https://github.com/scottellis) (I hope that's him, correct me if I'm wrong) and a C++ class for Omron D6T sensors by JoMu (someone from the Raspberry Pi forum). A zip file can be found in the following [link](http://www.raspberrypi.org/forums/viewtopic.php?f=44&t=47465).

I was using openFrameworks 0.8.0, but it should work with 0.8.1 as well. So the first thing to have for this example to work is a working copy of openFrameworks on your Raspberry Pi.

How to compile and run
----------------------

To compile, log in to your Raspberry Pi and navigate to the apps directory of your openFrameworks installation. If you've followed the instructions on the [openFrameworks website](http://openframeworks.cc), the address of your installation is `/home/pi/openFrameworks`. Navigate to the apps directory:

```bash
cd /home/pi/openFrameworks/apps
```

Press **enter**. If you issue `ls` and press **enter**, you will see the app categories there. By default there will be one category `myApps`. Change directory to it:

```bash
cd myApps
```

Hit **enter** and you are there. Make sure that your Pi has internet connection and [git](http://git-scm.com) installed. If not, find a way to connect to the net and install git like this:

```bash
sudo apt-get install git
```

Next step is to clone this repository. Enter the following in the Pi shell:

```bash
git clone https://github.com/kr15h/omron-d6t-44l-06-rpi-of-test.git
```

This will make a new directory in the apps folder with the name `omron-d6t-44l-06-rpi-of-test`. 

Navigate inside the newly created directory:

```bash
cd omron-d6t-44l-06-rpi-of-test
```

You will need the oF `Makefile` to be able to compile the example. Assuming that you are in the `omron-d6t-44l-06-rpi-of-test` directory, copy it from the default `emptyExample` like this:

```bash
cp /home/pi/openFrameworks/apps/myApps/emptyExample/Makefile ./
```

Issue `make && make run` to compile and run the example. Your sensor should be connected by then.

Dependencies
------------

Before you compile and connect the sensor, you should set up your Pi for using the I2C port. Refer to [this](http://www.instructables.com/id/Raspberry-Pi-I2C-Python/) guide to do that.

I think that you will need to install the i2c-dev package as well with:

```bash
sudo apt-get install i2c-dev
```

Hardware
--------

I used the [Bi-Directional Logic Level Converter from Sparkfun](https://www.sparkfun.com/products/12009) to transform the 5V I2C signals that the sensor uses to 3.3V of the Raspberry Pi.

You can find all the necessary information about the Omron human presence detection sensor (including pin layouts) [here](http://www.tme.eu/en/details/d6t-44l-06/temperature-transducers/omron/#).

Have fun!
