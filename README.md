# SuperSip
Sip server, with a system dependent number of threads to handle calls

The main thread does:
All sip adress management

The network thread:
-reads and sends SIP messages
-sends and receives RTP traffic
-supplies the web interface

The rest of the threads (at least one, maybe dozens) handle the sip calls.
