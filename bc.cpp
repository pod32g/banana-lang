#include <cstring>
#include <fstream>
#include <cstdio>
#include "banana.h"

Function read_compile(String input, String output) Start
	String name = output;
	name +=  ".cpp";

	std::ifstream read;
	std::ofstream write(name.c_str(), std::ofstream::binary);
	write << "#include \"banana.h\"\n";

	read.open(input.c_str());
	String payload;

	If read.is_open() Then Start
	
		String line;

		while(std::getline(read, line)){
			write << line << "\n";
		}

	End
		//Print name;
	read.close();
	write.close();

	String command = "g++ -o ";
	command += output;
	command += " ";
	command += name;

	System(command.c_str());

	If remove( name.c_str() ) != 0 Then Start
		Print "Error";
	End
	else{
		Print "Fine";
	}
End

int main(int argc, char const *argv[])
{
	//Print argc << std::endl;
	if (argc < 3){
		Print "Usage: \"bc output source\"\n";
		return 1;
	}else{
		read_compile(argv[2], argv[1]);
	}
	return 0;
}