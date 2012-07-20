/**
 * @file ExampleModule.cpp
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
 * Copyright © 2012 Anne van Rossum <anne@almende.com>
 *
 * @author  ...
 * @date    ...
 * @company Almende B.V.
 * @case    Artificial Intelligence Framework
 */

#include <ExampleSubModule.h>

#include <iostream>

using namespace rur;
using namespace std;

ExampleSubModule::ExampleSubModule() {

}

void ExampleSubModule::Init(std::string module_id) {
  ExampleModule::Init(module_id);
  file.open(GetParam()->filename.c_str(), ios::app);
}

void ExampleSubModule::Tick() {
  cout << "Read sensor (will be blocking)" << endl;
  std::vector<int> data = *readSensor();
  std::vector<int>::iterator i;
  cout << "Write to file: ";
  for (i = data.begin(); i != data.end(); ++i) {
    file << (*i) << " ";
    cout << (*i) << " ";
  }
  cout << endl;
  file << endl;
  //myfile.close();
}
