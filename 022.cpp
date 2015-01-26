/* Copyright 2015 ToxaKniotee */
#include <stdio.h>
#include <inttypes.h>   /* uint64_t, PRIu64 */
#include <vector>
#include <string>
#include <algorithm>    /* sort */

using std::vector;
using std::string;
using std::sort;

void load_file(string file_name, vector<string> *names);
unsigned get_value(int position, string name);

int main(int argc, char const *argv[]) {
    uint64_t total = 0;

    vector<string> names;
    load_file("files/p022.txt", &names);

    sort(names.begin(), names.end());

    for (int i = 0; i < names.size(); i++) {
        total += get_value(i + 1, names[i]);
    }

    printf("COLIN: %u\n", get_value(938, "COLIN"));

    printf("Total: %" PRIu64 "\n", total);
    return 0;
}

void load_file(string file_name, vector<string> *names) {
    FILE *pfile = fopen(file_name.c_str(), "r");
    char temp_char[50];
    string temp_string;

    while (fscanf(pfile, "%49s", &temp_char) != EOF) {
        temp_string = temp_char;
        names->push_back(temp_string);
    }

    fclose(pfile);
}

unsigned get_value(int position, string name) {
    unsigned sum = 0;
    for (int i = 0; i < name.length(); i++) {
        sum += static_cast<unsigned>(name[i] - 64);
    }
    return sum * position;
}
