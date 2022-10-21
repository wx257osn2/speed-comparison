#include <cstdio>
#include <cstdlib>

int main()
{
    unsigned rounds;
    const auto infile = std::fopen("rounds.txt", "r");    // open file
    if (infile == NULL) {
        std::perror("open file");
        return EXIT_FAILURE;
    }
    if (std::fscanf(infile, "%u", &rounds) != 1) {  // read from file
        std::perror("read file");
        return EXIT_FAILURE;
    }
    std::fclose(infile);                            // close file
    
    double pi = 1.0;
    
    for (unsigned i=1u ; i < rounds ; i += 4)
        pi += -1. / (2u * i + 1u) + 1. / (2u * i + 3u) - 1. / (2u * i + 5u) + 1. / (2u * i + 7u);
    
    pi *= 4.;
    std::printf("%.16f\n", pi); // print 16 decimal digits of pi
}
