#ifndef BPT_MEMORYRIVER_HPP
#define BPT_MEMORYRIVER_HPP

#include <fstream>

using std::string;
using std::fstream;
using std::ifstream;
using std::ofstream;

template<class T, int info_len = 1>
class MemoryRiver {
private:
    int tail = info_len*sizeof(int);
    fstream file;
    string file_name;
    int sizeofT = sizeof(T);
public:
    MemoryRiver() = default;

    MemoryRiver(const string& file_name) : file_name(file_name) {}

    void initialise(string FN = "") {
        if (FN != "") file_name = FN;
        file.open(file_name, std::ios::in | std::ios::out);
        int tmp = 0;
        for (int i = 0; i < info_len; ++i)
            file.write(reinterpret_cast<char *>(&tmp), sizeof(int));
        file.close();
    }

    void get_info(int &tmp, int n = 1) {
        if (n > info_len) return;
        file.open(file_name, std::ios::in);
        file.seekg((n - 1) * sizeof(int));
        file.read(reinterpret_cast<char *>(&tmp), sizeof(int));
        file.close();
    }

    void write_info(int tmp, int n = 1) {
        if (n > info_len) return;
        file.open(file_name, std::ios::in | std::ios::out);
        file.seekp((n - 1) * sizeof(int));
        file.write(reinterpret_cast<char *>(&tmp), sizeof(int));
        file.close();
    }

    int write(T &t) {
        file.open(file_name, std::ios::in | std::ios::out);
        file.seekp(tail);
        file.write(reinterpret_cast<char *>(&t), sizeofT);
        tail+=sizeofT;
        file.close();
        return tail-sizeofT;
    }

    void update(T &t, const int index) {
        file.open(file_name, std::ios::in | std::ios::out);
        file.seekp(index);
        file.write(reinterpret_cast<char *>(&t), sizeofT);
        file.close();
    }

    void read(T &t, const int index) {
        file.open(file_name, std::ios::in);
        file.seekg(index);
        file.read(reinterpret_cast<char *>(&t), sizeofT);
        file.close();
    }

//    void Delete(int index) {
//    }
};


#endif //BPT_MEMORYRIVER_HPP
