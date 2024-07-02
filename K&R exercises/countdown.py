import datetime
import time
import pytz
from art import *

# Set the end time to 11th July 2024 NZST
end_time = datetime.datetime(2024, 7, 11, 0, 0, 0, tzinfo=pytz.timezone('NZ'))

while True:
    # Calculate the time remaining
    time_remaining = end_time - datetime.datetime.now(pytz.timezone('NZ'))

    # Convert the time remaining to days
    days_remaining = time_remaining.days

    # Generate the ASCII art for the number of days remaining
    days_art = text2art(str(days_remaining), "block")

    # Print the time remaining
    print(days_art)
    print(str(time_remaining), "remaining until 11th July 2024 NZST")

    # Wait for 60 minutes
    time.sleep(60 * 60)
