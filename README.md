# NTRIP
GPS Correction data processor

NTRIP is a standard for receiving GPS CORS data. This allows for increased accuracy by providing local corrections to the received GPS signals. The data
is provided by a network connection to a CORS server, ideally located in close proximity to the receiver. In this project the network connection was
supplied by a cellular modem connected to the GPS.

The code was written to run on an embedded version of Windows which was installed on the GPS device.

This code as investigational. It was intended to determine if the cell modem connection would be reliable and fast enough to provide the correction and
the accuracy that we needed.

### Classes
- NTRIPCorrector: This is the class that receives the CORS data and processes it, passing it on to the GPS system.
- CorrectorMgr: Creates the corrector, the corrector controller, and creates required communications ports.
- CorrectorController: Starts the corrector, passes it the data to be processed, and verifies that the connection is still good.

## NTRIPTestDialog Subdirectory
This was a small test application that substituted for the live GPS processor. It allowed us to create a corrector
and run it as if it were passing data to a real GPS system.
