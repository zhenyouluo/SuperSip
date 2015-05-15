#include "networkreader.h"
#include "networkreaderthread.h"

void NetworkReaderThread::run()
{


  // create network reader object
  networkreader = new NetworkReader();

  // start event queue
  exec();


}

