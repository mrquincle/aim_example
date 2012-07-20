/**
 * @file ExampleModuleMain.cpp
 * @brief ...
 *
 * This file is created at Almende B.V. It is open-source software and part of the Common 
 * Hybrid Agent Platform (CHAP). A toolbox with a lot of open-source tools, ranging from 
 * thread pools and TCP/IP components to control architectures and learning algorithms. 
 * This software is published under the GNU Lesser General Public license (LGPL).
 *
 * It is not possible to add usage restrictions to an open-source license. Nevertheless,
 * we personally strongly object against this software being used by the military, in the
 * bio-industry, for animal experimentation, or anything that violates the Universal
 * Declaration of Human Rights.
 *
 * Copyright © 2012 Your Name <your@email.address>
 *
 * @author  ...
 * @date    ...
 * @company Almende B.V. (or your university, institute or company)
 * @case    Artificial Intelligence Module
 */
#include <ExampleSubModule.h>

#include <stdlib.h>
#include <iostream>

using namespace rur;
using namespace std;

/**
 * Every module is a separate binary and hence has its own main method. It is recommended
 * to have a version of your code running without any middleware wrappers, so preferably
 * have this file and the ExampleModule header and code in a separate "aim" directory.
 */
int main(int argc, char *argv[])  {
	ExampleSubModule *m = new ExampleSubModule();
	Param * param = m->GetParam();

	cout << "Make sure you start the yarp server before if build with YARP" << endl;
	cout << "Then run this binary" << endl;
	cout << "And connect using \"yarp connect \\examplesubmodule{id}\\sensor\"" << endl;
	if (argc < 3) {
		std::cout << "Usage: [identifier] [filename]" << endl;
		return EXIT_FAILURE;
	}
	std::string identifier = argv[1];
	m->Init(identifier);

	param->filename = argv[2];

	do {
		m->Tick();
	} while (true); 

	delete m;

	return EXIT_SUCCESS;
}
