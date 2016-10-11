# include <miner_states.H>
# include <miner.H>

void MinerWorking::exec(Miner * m)
{
  cout << "Sigo trabajando\n";
  
  m->add_stamina(-5);
  m->add_thirst(4);
  m->add_bladder(1);

  if (m->get_bladder() >= 40)
    {
      m->change_state(MinerInWc::get_ptr_instance());
      return;
    }

  if (m->get_stamina() <= 10)
    {
      m->change_state(MinerSleeping::get_ptr_instance());
      return;
    }

  if (m->get_thirst() >= 30)
    m->change_state(MinerDrinking::get_ptr_instance());
}

void MinerSleeping::exec(Miner * m)
{
  cout << "Zzzzz\n";
  
  Miner * miner = static_cast<Miner *>(m);
  
  m->add_stamina(10);
  m->add_bladder(3);
  m->add_thirst(1);

  if (m->get_bladder() >= 50)
    {
      m->change_state(MinerInWc::get_ptr_instance());
      return;
    }

  if (m->get_stamina() >= 100)
    {
      if (m->get_thirst() >= 30)
	m->change_state(MinerDrinking::get_ptr_instance());
      else if (m->get_bladder() >= 40)
	m->change_state(MinerInWc::get_ptr_instance());
      else  
	m->change_state(MinerWorking::get_ptr_instance());
    }
}

void MinerDrinking::exec(Miner * m)
{
  cout << "Ahhhh ¡Refrescante!\n";
  
  Miner * miner = static_cast<Miner *>(m);
  
  m->add_stamina(-1);
  m->add_bladder(5);
  m->add_thirst(-5);

  if (m->get_bladder() >= 40)
    {
      m->change_state(MinerInWc::get_ptr_instance());
      return;
    }

  if (m->get_stamina() <= 10)
    {
      m->change_state(MinerSleeping::get_ptr_instance());
      return;
    }

  if (m->get_thirst() <= 10)
    m->change_state(MinerWorking::get_ptr_instance());

}

void MinerInWc::exec(Miner * m)
{
  cout << "Ahhhh ¡Qué alivio!\n";
  
  Miner * miner = static_cast<Miner *>(m);
  
  m->add_stamina(-1);
  m->add_bladder(-10);
  m->add_thirst(2);

  if (m->get_bladder() < 10)
    m->set_last_state();
}
