#include <iostream>
#include <filesystem>
#include <fstream>
#include <type_traits>

typedef class Json
{
    private:
        std :: fstream file;
    public:
        Json(std :: string path)
        {
            //
            if (std :: filesystem :: exists(path))
            {
                file.open(path);
            }else 
            {
                throw std :: invalid_argument("Your File Was Not Found.");
            }
        }
        template<typename t>t find(std :: string name)
        {
            std :: string line;
            while(std :: getline(this->file,line))
            {
                std :: string Name = line,Data = line;
                Name.erase(Name.find(":"),Name.length);
                Data.erase(0,Data.find(":"));
                if(Name == name)
                {
                    if constexpr (std :: is_same_v(t,int))
                    {
                        try
                        {
                            return std :: stoi(Data);
                        }
                        catch(const std::exception& e)
                        {
                            throw std :: invalid_argument("The Data Its Not Int");
                        }
                    }else if constexpr (std :: is_same_v(t,float))
                    {
                        try
                        {
                            return std :: stof(Data);
                        }
                            catch(const std::exception& e)
                        {
                            throw std :: invalid_argument("The Data Its Not float");
                        }
                        
                    }else if constexpr (std :: is_same_v(t,double))
                    {
                        try
                        {
                            return std :: stod(Data);
                        }
                        catch(const std :: exception& e)
                        {
                            throw std :: invalid_argument("The Data Its Not Double");
                        }
                    }else if constexpr (std :: is_same_v(t,long long))
                    {
                        try
                        {
                            return std :: stoll(Data);
                        }
                        catch(const std::exception& e)
                        {
                            throw std :: invalid_argument("The Data Its Not Long Long");
                        }
                        break;
                    }else if constexpr (std :: is_same_v(t,long double))
                    {
                        try
                        {
                            return std :: stold(Data);
                        }
                        catch(const std::exception& e)
                        {
                            throw std :: invalid_argument("The Data Its Not Long Double");
                        }
                        break;
                    }else if constexpr (std :: is_same_v(t,unsigned long long))
                    {
                        try
                        {
                            return std :: stoull(Data);
                        }
                        catch(const std::exception& e)
                        {
                            throw std :: invalid_argument("The Data Its Not unsigned Long Long");
                        }
                        break;
                    }else if constexpr (std :: is_same_v(t,long))
                    {
                        try
                        {
                            return std :: stol(Data);
                        }
                        catch(const std::exception& e)
                        {
                            throw std :: invalid_argument("The Data Its Not Long");
                        }
                        break;
                    }else if constexpr (std :: is_same_v(t,unsigned long))
                    {
                        try
                        {
                            return std :: stoul(Data);
                        }
                        catch(const std::exception& e)
                        {
                            throw std :: invalid_argument("The Data Its Not unsigned Long");
                        }
                        break;
                    }else if constexpr (std :: is_same_v(t,bool))
                    {
                        if (Data == "true")
                        {
                            return true;
                        }
                        else if (Data == "false")
                        {
                            return false;
                        }
                        else
                        {
                            throw std :: invalid_argument("The Its Not Boolean.");
                        }
                    }
                }
            }
        }

};