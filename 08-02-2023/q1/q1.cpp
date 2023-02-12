#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Geno
{
    private:
        
    public:
        string g_str;
        Geno(string genom)
        {
            g_str = genom;
        }
        vector<int> find_ocorrence(string dna_chain)
        {
            vector<int> vector_indexes;
            for (int i = 0; i < g_str.size(); i++)
            {
                if (g_str[i] == dna_chain[0])
                {
                    int not_broken = 1;
                    for (int j = 1; j < dna_chain.size(); j++)
                    {
                        if (dna_chain[j] != g_str[i+j])
                        {
                            not_broken = 0;
                            break;
                        }
                    }
                    if (not_broken) vector_indexes.push_back(i);
                }
            }
            return vector_indexes;
        }
        
        vector<int> find_reversed_ocorrence(string dna_chain)
        {
            vector<int> vector_indexes = find_ocorrence(reversed_complement(dna_chain));
            return vector_indexes;
        }

        string reversed_complement(string dna_chain)
        {
            for (int i = 0; i < dna_chain.size(); i++)
            {
                if (dna_chain[i] == 'A') dna_chain[i] = 'T';
                else if (dna_chain[i] == 'T') dna_chain[i] = 'A';
                else if (dna_chain[i] == 'G') dna_chain[i] = 'C';
                else if (dna_chain[i] == 'C') dna_chain[i] = 'G';
            }
            string reversed_dna;
            for (int i = dna_chain.size()-1; i >= 0; i--)
            {
                reversed_dna.push_back(dna_chain[i]);
            }
            return reversed_dna;
        }

        void find_ocorrences_from_file(string file_name, string file_name_out)
        {
            ifstream dna_file(file_name);
            ofstream out_file(file_name_out);
            string string_buffer;
            int i = 0;
            while (true)
            {
                getline(dna_file, string_buffer);
                if (string_buffer[0] == '0') break;
                out_file << "Teste " << i++ << endl;
                getline(dna_file, string_buffer);
                string p = string_buffer;
                getline(dna_file, string_buffer);
                g_str = string_buffer;
                out_file << "ocorrência direta: ";
                for (int index : find_ocorrence(p)) out_file << ' ' << index+1;
                out_file << endl;
                out_file << "ocorrência complementar invertida: ";
                for (int index : find_reversed_ocorrence(p)) out_file << ' ' << index+1;
                out_file << endl;
                out_file << '\n';
                if (i > 1000) break;
            }
            dna_file.close();
            out_file.close();
        }

};

int main()
{
    Geno geno("TCATATGCAAATAGCTGCATACCGA");
    vector<int> ocorrences = geno.find_ocorrence("CATA");
    for (int index : ocorrences)
    {
        cout << index << endl;
    }
    ocorrences = geno.find_reversed_ocorrence("CATA");
    for (int index : ocorrences)
    {
        cout << index << endl;
    }
    geno.find_ocorrences_from_file("genoma.in", "genoma.out");
    return 0;
}