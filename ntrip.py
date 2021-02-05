#!/usr/bin/python
""" Test NTRIP connection to known CORS server """

import httplib
import base64

# Various userid/password combinations used in testing 
# pw = base64.encodestring("HGPS_TEST:abc123")
pw = base64.encodestring("Casey:Hemi1")
# pw = base64.encodestring("Hemi1:Hemi1")
# conn = httplib.HTTPConnection("208.77.60.71:5000")
conn = httplib.HTTPConnection("98.177.224.229:8025")
# conn = httplib.HTTPConnection("65.118.186.122:8080")

# Set up HTTP request headers and establish NTRIP connection
headers = {"Host":"98.177.224.229:8025","Ntrip-Version":"Ntrip/2.0","User-Agent":"NtripClientPOSIX","Authorization":"Basic " + pw}
conn.request("GET","/NorthScottsdale","\r\n",headers)
r1 = conn.getresponse()

# Display response data from NTRIP server
print "Response: ", r1.status, r1.reason
print "Data: "
while 1:
	data1 = r1.read(50)
	print data1
