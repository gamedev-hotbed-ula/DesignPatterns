# include <unistd.h>
# include <string>
# include <random>

# include <miner.H>


int main(int argc, char * argv[])
{
  size_t num_it = argc < 2 ? 1000 : stoul(argv[1]);
  size_t delay = argc < 3 ? 0 : stoul(argv[2]);

  Miner miner;

  std::mt19937_64 rng(time(0)%std::mt19937_64::max());
  std::exponential_distribution<double> dist(2);

  for (size_t i = 0; i < num_it; ++i)
    {
      double dt = dist(rng);
      cout << "dt: " << dt << " minutes\n";
      miner.update(dt);
      usleep(delay);
    }

  return 0;    
}
