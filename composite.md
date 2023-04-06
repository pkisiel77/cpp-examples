@startuml

class Component {
    + operation(): void
    + add(c: Component): void
    + remove(c: Component): void
    + getChild(n: int): Component
}

class Leaf {
    + operation(): void
}

class Composite {
    + operation(): void
    + add(c: Component): void
    + remove(c: Component): void
    + getChild(n: int): Component
}

Component <|-- Leaf
Component <|-- Composite
Composite o-- Component

@enduml
