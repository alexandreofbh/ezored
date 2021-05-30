# Commands

Every command script in ezored is a python file. 

All commands are simple functions that will receive command line arguments and based on this arguments will executed desired operations. Example:

```python make.py clean```

With this execution ezored will search for a file with path **"files/commands/clean.py"** and will send all parameter to a function called **"run"** inside file **clean.py**.

If you don't remember what commands are available you can type only this to list all commands:

```python make.py```

If you want create your own commands you only need put it inside folder **"files/commands"** and **ezored**.
