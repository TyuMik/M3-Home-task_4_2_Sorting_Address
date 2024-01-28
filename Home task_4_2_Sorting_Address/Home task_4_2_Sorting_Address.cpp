
#include <iostream>
#include <fstream>
#include <string>

class Address {
private:
    std::string city;
    std::string street;
    int house;
    int flat;
public:
    Address() { }
    void set_city(std::string city) {
        this->city = city;
    }
    void set_street(std::string street) {
        this->street = street;
    }
    void set_house(int house) {
        this->house = house;
    }
    void set_flat(int flat) {
        this->flat = flat;
    }
    std::string get_city() {
        return city;
    }
    std::string get_street() {
        return street;
    }
    int get_house() {
        return house;
    }
    int get_flat() {
        return flat;
    }
    std::string getNewAddress() {
        std::string new_address = city + ", " + street + ", " + std::to_string(house) + ", " + std::to_string(flat);
        return new_address;
    }
    void sort(Address* address, int size) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (address[j].get_city() > address[j + 1].get_city()) {
                    std::string tmp_city = address[j].get_city();
                    std::string tmp_street = address[j].get_street();
                    int tmp_house = address[j].get_house();
                    int tmp_flat = address[j].get_flat();
                    address[j].set_city(address[j + 1].get_city());
                    address[j].set_street(address[j + 1].get_street());
                    address[j].set_house(address[j + 1].get_house());
                    address[j].set_flat(address[j + 1].get_flat());
                    address[j + 1].set_city(tmp_city);
                    address[j + 1].set_street(tmp_street);
                    address[j + 1].set_house(tmp_house);
                    address[j + 1].set_flat(tmp_flat);
                }
            }
        }
    }
};

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Russian");

    std::ifstream input_data("in.txt");
    if (input_data.is_open()) {

        int N, house, flat;
        std::string city, street;

        input_data >> N;

        Address* input_address = new Address[N];

        for (int i = 0; i < N; i++) {
            input_data >> city >> street >> house >> flat;
            input_address[i].set_city(city);
            input_address[i].set_street(street);
            input_address[i].set_house(house);
            input_address[i].set_flat(flat);
        }

        input_data.close();

        std::ofstream output_data("out.txt");
        output_data << N << std::endl;
        input_address->sort(input_address, N);
        for (int i = 0; i < N; i++) {
            output_data << input_address[i].getNewAddress() << std::endl;
        } 
        output_data.close();
        delete[] input_address;
    }
    else {
        std::cout << "Ошибка! Не удалось открыть файл";
    }
    return 0;
}