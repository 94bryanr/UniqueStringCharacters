#include<iostream>
using std::cout;
using std::endl;

// Returns true if all 8 bit characters are unique. False otherwise.
bool isUnique(char* string){
    char* visited = (char*)calloc(1, 32);
    unsigned short stringIndex = 0;
    while(*(string + stringIndex) != '\0'){
        char current = *(string + stringIndex);
        short bitIndex = current % 8;
        char bitMask = 1 << bitIndex;
        if((visited[current / 8] & bitMask) > 0)
            return false;
        visited[current / 8] = visited[current / 8] | bitMask;
        stringIndex++;
    }
    free(visited);
    return true;
}

// Prints the result of argument 1 having all unique characters.
int main(int argc, char* argv[]){
    if(argc != 2)
        exit(0);
    char* string = argv[1];
    bool unique = isUnique(string);
    if(unique)
        cout << string << " is unique" << endl;
    else
        cout << string << " is not unique" << endl;
}