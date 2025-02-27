#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

struct _pixel
{
    float r;
    float g;
    float b;
    int x;
    int y;
};
typedef struct _pixel Pixel;

void flipVertically(std::vector<Pixel> &pixelList)
{
    int n = pixelList.size();
    for (int i = 0; i < n / 2; ++i)
    {
        std::swap(pixelList[i], pixelList[n - i - 1]);
    }
}


//sparce the file
Pixel makePixel(std::string& line)
{
    Pixel pixel;
    long long unsigned int pos;
    // parsing the x value
    pos = line.find(',');
    pixel.x = std::stoi(line.substr(0, pos));
    line = line.substr(pos + 1);
    // parsing the y value
    pos = line.find(',');
    pixel.y = std::stoi(line.substr(0, pos));
    line = line.substr(pos + 1);
    // parsing the r value
    pos = line.find(',');
    pixel.r = std::stof(line.substr(0, pos));
    line = line.substr(pos + 1);
    // parsing the g value
    pos = line.find(',');
    pixel.g = std::stof(line.substr(0, pos));
    line = line.substr(pos + 1);
    // parsing the b value
    pixel.b = std::stof(line);

    return pixel;
}

//average
void averageColors(std::vector<Pixel> &pixelList)
{
    float averageR=0.0;
    
    for (int i = 0; i < pixelList.size(); i++)
    {
        averageR += pixelList[i].r;
    }
    averageR /= pixelList.size();
    
    std::cout << "Average color is: " << averageR << "\n";
};


//main
int main(int argc, char *argv[])
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
        averageColors(pixelList);
        flipVertically(pixelList);

        // Open the output file
        std::ofstream out("flipped.dat");
        if (out.is_open())
        {
            for (int i = 0; i < pixelList.size(); i++)
            {
                out << pixelList[i].x << ',' << pixelList[i].y << ',' << pixelList[i].r << ',' << pixelList[i].g << ',' << pixelList[i].b << '\n';
            }
            out.close();
        }
        else
        {
            std::cerr << "Unable to open output file" << std::endl;
        }
    }
    else
    {
        std::cerr << "Unable to open input file" << std::endl;
    }

    return 0;
}