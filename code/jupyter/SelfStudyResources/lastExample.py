'''
file: lastExample.py

author: Peter Mackenzie-Helnwein, University of Washington, Seattle, WA
created: 07-28-2020
'''

# imports
import sys
import argparse

# the main function
def main():

    parser = argparse.ArgumentParser(description='Your final challenger')

    parser.add_argument('--name', action='store', required=True,
                       help='your name.  Use quotes if your name contains spaces')
    parser.add_argument('--done', required=True, action='store', nargs=1, choices=['all','some','none'], 
               help='You are telling me that you are done with {all or some or none} of the assignments.')
    parser.add_argument('-L', action='store_true', help='set this option if you liked this python tutorial')

    args = parser.parse_args(sys.argv[1:])

    s = \
"""
Hi {},

Looks like you've done {} of the assignments.
""".format(args.name,*(args.done))

    if 'all' in args.done:
        s += "Great job!\n"
    elif 'some' in args.done:
        s += "Nice job!\n"
    elif 'none' in args.done:
        s += "Hey, at least you are working on this one:)\n"

    if args.L:
        s += "\nSo glad you liked this tutorial :)\n"
    else:
        s += \
"""
Looks like you didn't really like this tutorial.
Please leave me some suggestions on how to do better
in the feedback survey. Thanks.
"""

    s += "\nHope to see you again soon,\nPeter\n"

    print(s)


# the actual execution
if __name__ == '__main__':
    sys.exit(main())

