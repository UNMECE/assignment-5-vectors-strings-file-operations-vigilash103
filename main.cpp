#include <iostream>
#include <vector>
#include <string>
#include <fstream>

struct _pixel
{
    float r;
    float g;
    float b;
    int x;
    int y;
};
typedef struct _pixel Pixel;

Pixel makePixel(std::string line)
{
    Pixel pixel;
    int pos;
    pos = line.find(',');
    pixel.x = std::stoi(line.substr(0, pos));
    line = line.substr(pos + 1);
    pixel.y = std::stoi(line.substr(0, pos));
    line = line.substr(pos + 1);
    pixel.r = std::stof(line.substr(0, pos));
    line = line.substr(pos + 1);
    pixel.g = std::stof(line.substr(0, pos));
    line = line.substr(pos + 1);
    pixel.b = std::stof(line);
    return pixel;
}

int main()
{
    std::vector<Pixel> pixelList;
    std::ifstream in("pixels.dat");
    std::string line;


    if (in.is_open())
    {
        while (getline(in, line))
        {
            std::cout << line << std::endl;
            pixelList.push_back(makePixel(line));
        }

        in.close();
    }

    return 0;
}

void averageColors(std::vector<Pixel> &pixelList)
{

}

void flipVertically(std::vector<Pixel> &pixelList)
{

}