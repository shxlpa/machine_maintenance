import digitalio
import busio
import board
from adafruit_epd.epd import Adafruit_EPD
from adafruit_epd.il0373 import Adafruit_IL0373

# create the spi device and pins we will need
# Define SPI pins
spi_clk = board.GP18  # Replace with the actual pin for SPI clock
spi_mosi = board.GP19  # Replace with the actual pin for SPI MOSI
spi_miso = board.GP16  # Replace with the actual pin for SPI MISO
spi_cs = board.GP17  # Replace with the actual pin for SPI CS

# Create SPI bus
spi = busio.SPI(clock=spi_clk, MOSI=spi_mosi, MISO=spi_miso)

#spi = busio.SPI(board.SCK, MOSI=board.MOSI, MISO=board.MISO) #original code

ecs = digitalio.DigitalInOut(board.GP21)
dc = digitalio.DigitalInOut(board.GP20)
srcs = None    # can be None to use internal memory
rst = None    # can be None to not use this pin
busy = None   # can be None to not use this pin

# give them all to our driver
print("Creating display")
display = Adafruit_IL0373(104, 212, spi,          # 2.13" Tri-color display
                          cs_pin=ecs, dc_pin=dc, sramcs_pin=srcs,
                          rst_pin=rst, busy_pin=busy)

display.rotation = 1

# clear the buffer
print("Clear buffer")
display.fill(Adafruit_EPD.WHITE)
display.pixel(10, 100, Adafruit_EPD.BLACK)

print("Draw Rectangles")
display.fill_rect(5, 5, 10, 10, Adafruit_EPD.RED)
display.rect(0, 0, 20, 30, Adafruit_EPD.BLACK)

print("Draw lines")
display.line(0, 0, display.width-1, display.height-1, Adafruit_EPD.BLACK)
display.line(0, display.height-1, display.width-1, 0, Adafruit_EPD.RED)

print("Draw text")
#display.text('hello world', 25, 10, Adafruit_EPD.BLACK)
display.display()