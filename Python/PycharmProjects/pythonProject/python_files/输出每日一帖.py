import datetime


mot = ["monday：\nOur destiny offers us not the wine of despair, but the cup of hope.",
       "tuesday：\nWhere there is a will, there is a way.",
       "wednesday：\nBelieve that nothing is impossible.",
       "thursday：\nToday i will waiting for love, waiting for my love!",
       "friday：\nIf winter comes,can spring be far from?",
       "saturday：\nDon't forget why we depart, and what we believe everytime.",
       "sunday：\nStay hungry, Stay foolish."]
day = datetime.datetime.now().weekday()
print(day)
print(mot[day])

