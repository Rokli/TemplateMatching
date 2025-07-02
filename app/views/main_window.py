from tkinter import ttk


class MainWindow:
    def __init__(self, root):
        self.root = root
        self.root.title("Template Matching")
        self.create_widgets()

    def create_widgets(self):
        self.label = ttk.Label(self.root, text="Привет, Tkinter!")
        self.label.pack(padx=20, pady=20)