# include <miner_states.H>
# include <miner.H>

void MinerWorking::update(Miner * m, double dt)
{
  cout << "Sigo trabajando\n";
  
  m->add_stamina(-5*dt);
  m->add_thirst(4*dt);
  m->add_bladder(1*dt);

  if (m->get_bladder() >= 40)
    {
      m->change_state("wc");
      return;
    }

  if (m->get_stamina() <= 10)
    {
      m->change_state("sleeping");
      return;
    }

  if (m->get_thirst() >= 30)
    m->change_state("drinking");
}

void MinerSleeping::update(Miner * m, double dt)
{
  cout << "Zzzzz\n";
  
  Miner * miner = static_cast<Miner *>(m);
  
  m->add_stamina(10*dt);
  m->add_bladder(3*dt);
  m->add_thirst(1*dt);

  if (m->get_bladder() >= 50)
    {
      m->change_state("wc");
      return;
    }

  if (m->get_stamina() >= 100)
    {
      if (m->get_thirst() >= 30)
	m->change_state("drinking");
      else if (m->get_bladder() >= 40)
	m->change_state("wc");
      else  
	m->change_state("working");
    }
}

void MinerDrinking::update(Miner * m, double dt)
{
  cout << "Ahhhh ¡Refrescante!\n";
  
  Miner * miner = static_cast<Miner *>(m);
  
  m->add_stamina(-1*dt);
  m->add_bladder(5*dt);
  m->add_thirst(-5*dt);

  if (m->get_bladder() >= 40)
    {
      m->change_state("wc");
      return;
    }

  if (m->get_stamina() <= 10)
    {
      m->change_state("sleeping");
      return;
    }

  if (m->get_thirst() <= 10)
    m->change_state("working");

}

void MinerInWc::update(Miner * m, double dt)
{
  cout << "Ahhhh ¡Qué alivio!\n";
  
  Miner * miner = static_cast<Miner *>(m);
  
  m->add_stamina(-1);
  m->add_bladder(-10);
  m->add_thirst(2);

  if (m->get_bladder() < 10)
    m->set_last_state();
}
