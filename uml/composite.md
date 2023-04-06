```mermaid
classDiagram
    Component "1" *-- "0..*" Composite : contains
    Component <|-- Leaf
    Component <|-- Composite
    class Component {
        +operation(): void
        +add(c: Component): void
        +remove(c: Component): void
        +getChild(n: int): Component
    }
    class Leaf {
        +operation(): void
    }
    class Composite {
        +operation(): void
        +add(c: Component): void
        +remove(c: Component): void
        +getChild(n: int): Component
    }
````
