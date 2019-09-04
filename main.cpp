#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

struct rotor{
    int * alphabet_num;

    int current_position = 0;

    int turnover_num;
    int * turnover;

    bool changed = false;

};

struct reflector{
    int * alphabet_num;
};

int mod(int a, int b){
    return (a % b + b ) % b;
}

int encode(int num_of_rotors, int alphabet_size, rotor * rotors, reflector reflector, int input){
    int pos = 0;
    for (int i = 0; i < num_of_rotors; i++) {
        if (i == 0) {
            rotors[i].current_position = mod(++rotors[i].current_position, alphabet_size);
            rotors[i].changed = true;

            pos = rotors[i].current_position + input;
            pos = mod(pos, alphabet_size);
        } else {
            pos += (rotors[i].current_position - rotors[i - 1].current_position);
            pos = mod(pos, alphabet_size);
        }
        pos = rotors[i].alphabet_num[pos];
        pos = mod(pos, alphabet_size);

        for (int k = 0; k < rotors[i].turnover_num; k++) {
            if (i != num_of_rotors - 1 && rotors[i].current_position == rotors[i].turnover[k] &&
                rotors[i].changed) {
                rotors[i + 1].current_position = mod(++rotors[i + 1].current_position, alphabet_size);
                rotors[i + 1].changed = true;
            }
        }
    }

    for (int i = 0; i < num_of_rotors; i++) {
        rotors[i].changed = false;
    }

    pos -= rotors[num_of_rotors - 1].current_position;
    pos = mod(pos, alphabet_size);

    pos = reflector.alphabet_num[pos];
    pos = mod(pos, alphabet_size);

    pos += rotors[num_of_rotors - 1].current_position;
    pos = mod(pos, alphabet_size);

    for (int i = num_of_rotors - 1; i >= 0; i--) {
        for (int k = 0; k < alphabet_size; k++) {
            if (rotors[i].alphabet_num[k] == pos) {
                pos = k;
                break;
            }
        }

        if (i != 0) {
            pos -= (rotors[i].current_position - rotors[i - 1].current_position);
            pos = mod(pos, alphabet_size);
        }
    }

    pos -= rotors[0].current_position;
    pos = mod(pos, alphabet_size);

    return pos;

}

int main() {

    int alphabet_size;

    scanf("%d", &alphabet_size);

    string * alphabet;
    alphabet = new string[alphabet_size];

    for (int i = 0; i < alphabet_size; i++){
        cin >> alphabet[i];
    }

    int rotors_number;
    scanf("%d", &rotors_number);

    rotor * rotors = new rotor[rotors_number];

    for (int i = 0; i < rotors_number; i++) {
        rotors[i].alphabet_num = new int[alphabet_size];

        for (int k = 0; k < alphabet_size; k++) {
            string tmp_input;
            cin >> tmp_input;
            for (int j = 0; j < alphabet_size; j++){
                if (tmp_input == alphabet[j]){
                    rotors[i].alphabet_num[k] = j;
                    break;
                }
            }
        }

        int turnover_num;

        scanf("%d", &turnover_num);

        rotors[i].turnover_num = turnover_num;

        string *rotor_def = new string[turnover_num];

        for (int j = 0; j < turnover_num; j++) {
            cin >> rotor_def[j];
        }

        rotors[i].turnover = new int[turnover_num];
        for (int k = 0; k < turnover_num; k++) {
            for (int j = 0; j < alphabet_size; j++) {
                if (rotor_def[k] == alphabet[j]) {
                    rotors[i].turnover[k] = j;
                    break;
                }
            }
        }

        delete[] rotor_def;
    }

    int reflectors_number;
    scanf("%d", &reflectors_number);

    reflector * reflectors = new reflector[reflectors_number];

    for (int i = 0; i < reflectors_number; i++){
        reflectors[i].alphabet_num = new int[alphabet_size];

        for (int k = 0; k < alphabet_size; k++){
            string tmp_input;
            cin >> tmp_input;
            for (int j = 0; j < alphabet_size; j++){
                if (tmp_input == alphabet[j]){
                    reflectors[i].alphabet_num[k] = j;
                    break;
                }
            }
        }
    }

    int texts_number = 0;
    scanf("%d", &texts_number);

    for (int i = 0; i < texts_number; i++){
        int machine_rotors_num = 0;
        scanf("%d", &machine_rotors_num);

        rotor * machine_rotors = new rotor[machine_rotors_num];

        for (int k = 0; k < machine_rotors_num; k++){
            int rotor_index = 0;
            scanf("%d", &rotor_index);

            string rotor_init_pos;
            cin >> rotor_init_pos;

            int rotor_init_pos_int = 0;

            for (int j = 0; j < alphabet_size; j++){
                if (rotor_init_pos == alphabet[j]){
                    rotor_init_pos_int = j;
                    break;
                }
            }
            machine_rotors[k] = rotors[rotor_index];
            machine_rotors[k].current_position = rotor_init_pos_int;
        }

        int machine_reflector_index = 0;
        scanf("%d", &machine_reflector_index);

        reflector ref = reflectors[machine_reflector_index];

// text input

        string text_input;
        string text_output;

        char symbol;
        do {
            symbol = getchar();
            if (symbol >= '0' && symbol <= '~'){
                text_input += symbol;
            }
        } while(symbol != '$');

//        text_input.pop_back();

        int text_size = text_input.size();

        vector<int> alphabet_num;

        string gather;
        for (int j = 0; j < text_size; j++){
            gather += text_input[j];
            for (int k = 0; k < alphabet_size; k++){
                if (gather == alphabet[k]){
                    alphabet_num.push_back(k);
                    gather = "";
                    break;
                }
            }
        }

        for (int j = 0; j < alphabet_num.size(); j++){
            int alph_pos = encode(machine_rotors_num, alphabet_size, machine_rotors, ref, alphabet_num[j]);
            text_output+= alphabet[alph_pos];
        }

        cout << text_output << "\n";

        delete[] machine_rotors;
    }


    delete[] alphabet;

    for (int i = 0; i < rotors_number; i++){
        delete[] rotors[i].alphabet_num;
        delete[] rotors[i].turnover;
    }
    delete[] rotors;

    for (int i = 0; i < reflectors_number; i++){
        delete[] reflectors[i].alphabet_num;
    }
    delete[] reflectors;

    return 0;
}
