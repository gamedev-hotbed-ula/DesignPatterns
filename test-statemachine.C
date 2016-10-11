# include <unistd.h>
# include <string>

# include <miner.H>

int main(int argc, char * argv[])
{
  size_t num_it = argc < 2 ? 1000 : stoul(argv[1]);
  size_t delay = argc < 3 ? 0 : stoul(argv[2]);

  Miner miner;

  for (size_t i = 0; i < num_it; ++i)
    {
      miner.exec();
      usleep(delay);
    }

  return 0;    
}
