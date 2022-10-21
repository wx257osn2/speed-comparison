#include <cstdio>
#include <cstdlib>

unsigned rounds;
double pi = 1.0;

int main()
{
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
    
    rounds += 2u; // do this outside the loop
    
    for (unsigned i=2u ; i < rounds ; ++i) // use ++i instead of i++
    {
        const double x = -1.0 + 2.0 * (i & 0x1); // allows vectorization
        pi += (x / (2u * i - 1u)); // double / unsigned = double
    }
    
    pi *= 4.;
    std::printf("%.16f\n", pi); // print 16 decimal digits of pi
}
