import math

valueList = []

for x in range(0, 60) :
	valueList.append(0)

sineWidth = 136
for x in range(0, sineWidth) :
	
	value = float(x)/ float(sineWidth)
	sinArg = math.pi * (value)
	print value
	print sinArg
	valueList.append(int(math.sin(sinArg)*150))

for x in range(0, 60) :
	valueList.append(0)

print valueList

print len(valueList)

writeFile = open('NewSin.h', 'w')
writeFile.write('uint8_t const cos_wave[256] PROGMEM = {\n')
for x in range(0, 256) :
	writeFile.write(str(valueList[x]))

	if x < 255 :
		writeFile.write(',')

writeFile.write('};\n')

writeFile.close()