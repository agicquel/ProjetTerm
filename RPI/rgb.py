import time
# Import the TCS34725 module.
import Adafruit_TCS34725
# Create a TCS34725 instance with default integration time (2.4ms) and gain (4x).
import smbus
tcs = Adafruit_TCS34725.TCS34725()
tcs.set_interrupt(False)

# Read the R, G, B, C color data.
r, g, b, c = tcs.get_raw_data()

# Print out the values.
print('Color: red={0} green={1} blue={2} clear={3}'.format(r, g, b, c))
fichier = open("rouge.tmp", "w")
fichier.write(str(r))
fichier.close()
