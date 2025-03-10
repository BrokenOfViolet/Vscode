import subprocess                      # simulate the terminal to execute the command.
import time


def exec_command(command):
    command = command.rstrip()
    child = subprocess.run(command, shell=True)
    if child.returncode != 0:
        time.sleep(0.1)
        print("Can not execute this command.")
    return child


while True:
    execute = input("(press 'q' to quit)>>>")
    if execute == "q":
        print("The program exit.")
        break
    else:
        output = exec_command(execute)