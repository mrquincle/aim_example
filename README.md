<!-- Uses markdown syntax for neat display at github -->

# AIM Example
AIM stands for Artificial Intelligence Modules.

## How to get and build this module?
* git clone https://github.com/mrquincle/aim_example.git
* cd aim_example
* make

## How to run this module?
* yarp server & # in seperate console, install YARP if you don't have it
* cd build 
* ./ExampleModule 12 output.log

The expected result:

	Make sure you start the yarp server before if build with YARP
	Then run this binary
	And connect using "yarp connect /examplemodule{id}/sensor"
	yarp: Port /examplemodule12/sensor active at tcp://127.0.0.1:10002
	yarp: Port /examplemodule12/sensorarraylength active at tcp://127.0.0.1:10003
	yarp: Port /examplemodule12/result active at tcp://127.0.0.1:10004
	Read sensor (will be blocking)

Now you can try to write to it, start again another console, and:

* yarp write /write /examplemodule12/sensor

This will output:
	yarp: Port /write active at tcp://127.0.0.1:10005
	yarp: Sending output from /write to /examplemodule12/sensor using tcp
	23 2 3 4

And the reaction:

	yarp: Receiving input from /write to /examplemodule12/sensor using tcp
	Write to file: 23 2 3 4 
	Read sensor (will be blocking)

That's all!

## Copyrights
The copyrights (2012) belong to:

- Author: Anne van Rossum
- Author: Scott Guo
- Almende B.V., http://www.almende.com and DO bots B.V., http://www.dobots.nl
- Rotterdam, The Netherlands
