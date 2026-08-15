#include <iostream>
#include <fstream>
#include <filesystem>

typedef class Json
{
    private :
        std :: fstream file;
        bool dts = false;
    public :
        Json(std :: string path)
        {
            bool a = std :: filesystem ::exists(path);
            if (a)
            {
                file.open(path,std :: ios :: openmode :: _S_in);
            }else 
            {
                file = std :: fstream(path,std :: ios :: openmode :: _S_in);
                file << "{\n";
            }
        }
        void operator[](std :: string Heloo)
        {
            this->dts = true;
            
        }
        void operator<<(std :: string lolo)
        {
            if (this->dts)
            {

            }else 
            {
                throw std :: invalid_argument("Your Data Was Not Have The Name.");
            }
        }
        void find(std :: string data)
        {
            std :: string line;
            while(std :: getline(this->file,line))
            {
                
            }
        }
};