import bd_message, datetime

today = datetime.date.today()
print(today)
bd = datetime.date(2025, 11, 24)
print(bd)

time_difference = bd - today 
print(time_difference)

if bd == today:
    bd_message.anniv()
else:
    print(f"My birthday is {time_difference.days} left.")