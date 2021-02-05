#!/usr/bin/python
import httplib
# conn = httplib.HTTPConnection("208.77.60.71:5000")
conn = httplib.HTTPConnection("98.177.224.229:8025")
headers = {"Host":"208.77.60.71:5000","Ntrip-Version":"Ntrip/2.0","User-Agent":"NtripClientPOSIX"}
conn.request("GET","")
r1 = conn.getresponse()
print "Response: ", r1.status, r1.reason
data1 = r1.read()
print "Data: ", data1
