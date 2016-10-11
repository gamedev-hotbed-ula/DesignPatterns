# ifndef MINER_STATES_H
# define MINER_STATES_H

# include <iostream>

using namespace std;

# include <singleton.H>
# include <statemachine.H>

class Miner;

class MinerWorking :
  public Singleton<MinerWorking>,
  public State<Miner>
{
  friend class Singleton<MinerWorking>;
  
protected:
  MinerWorking() { }
  
public:
  void enter(Miner *)
  {
    cout << "Estoy comenzando a trabajar\n";
  }
  
  void exec(Miner *);

  void exit(Miner *)
  {
    cout << "¡Debo parar de trabajar!\n";
  }
};

class MinerSleeping :
  public Singleton<MinerSleeping>,
  public State<Miner>
{
  friend class Singleton<MinerSleeping>;
  
protected:
  MinerSleeping() { }
  
public:
  void enter(Miner *)
  {
    cout << "Estoy exhausto, voy a dormir\n";
  }
  
  void exec(Miner *);

  void exit(Miner *)
  {
    cout << "¡Debo levantame!\n";
  }
};

class MinerDrinking :
  public Singleton<MinerDrinking>,
  public State<Miner>
{
  friend class Singleton<MinerDrinking>;
  
protected:
  MinerDrinking() { }

public:
  void enter(Miner *)
  {
    cout << "Tengo sed, necesito una bebida\n";
  }
  
  void exec(Miner *);

  void exit(Miner *)
  {
    cout << "¡Ya calmé mi sed!\n";
  }
};

class MinerInWc :
  public Singleton<MinerInWc>,
  public State<Miner>
{
  friend class Singleton<MinerInWc>;
  
protected:
  MinerInWc() { }

public:
  void enter(Miner *)
  {
    cout << "Necesito ir al baño\n";
  }
  
  void exec(Miner *);

  void exit(Miner *)
  {
    cout << "¡Listo! De vuelta a lo mío\n";
  }
};

# endif // MINER_STATES_H
