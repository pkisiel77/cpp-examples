# 10 - Projects

This chapter collects larger project assignments. A project should connect the
previous course topics: language basics, functions, STL, classes, files, tests,
project structure, and short documentation.

## Learning Goals

After this chapter you should be able to:

- choose a project topic and narrow its scope,
- split a solution into smaller modules,
- choose containers and classes for the problem,
- prepare a compilable multi-file project,
- add simple tests or manual verification scenarios,
- write user and technical documentation,
- describe limitations and possible extensions.

## Project Categories

Choose the smallest project that still lets you practice the intended material.
A stable minimum version is more valuable than an unfinished large idea.

### Console Tools

- logger,
- calculator,
- matrix calculator,
- CSV parser,
- tic-tac-toe.

These are good first projects because they can run in a terminal and usually do
not require external libraries.

### User-Facing Systems

- order queue,
- vehicle database,
- task management system,
- ATM simulator.

These projects practice classes, containers, validation, file storage, and menu
flows.

### Games

- Tetris,
- Snake,
- Pac-Man.

Games are larger because they combine state, loops, input, rendering, and many
edge cases. They should be treated as extended projects.

## How to Choose a Project

Before accepting a topic, answer these questions:

- Can you describe the minimum version in five bullet points?
- Can the first version run in the terminal without extra libraries?
- Can you build a working version in one or two class sessions?
- Do you know what data the program stores or processes?
- Can you name three verification scenarios?

If several answers are unclear, reduce the scope or choose a simpler topic.

## Minimum Version First

Every project should have a minimum version and optional extensions.

The minimum version:

- compiles,
- runs,
- implements the required core behavior,
- handles at least one invalid input case,
- can be demonstrated from start to finish.

The extended version:

- includes the minimum version,
- adds at least two useful extensions,
- does not break the core behavior,
- documents what was added.

Extensions should never hide a broken minimum version.

## Suggested Project Structure

A practical student project can use this structure:

```text
project-name/
  include/
  src/
  tests/
  data/
  build/
  README.md
  build.sh
```

Keep generated files in `build/`. Commit source files, tests, documentation,
and small sample input files when they are needed.

## README Checklist

The project `README.md` should include:

- project goal,
- build command,
- run command,
- minimum feature list,
- optional extensions,
- directory structure or important files,
- example input or usage,
- known limitations.

The README does not need to be long. It must be enough for another person to
build, run, and understand the project.

## Final Project Checklist

Use this checklist before submitting a project.

Minimum behavior:

- all minimum requirements are implemented,
- the main menu or main usage flow is understandable,
- the basic use case works from start to finish,
- at least one invalid input case is handled,
- the program does not crash on a common user mistake.

Build and run:

- `README.md` contains a build command,
- `README.md` contains a run command,
- the project compiles with `-Wall -Wextra -pedantic`,
- the project does not require manually generated files,
- build artifacts are not committed.

Code organization:

- code is split into functions or methods by responsibility,
- `main` starts the program but does not contain all logic,
- source files have clear names,
- larger projects separate declarations and definitions,
- names of variables, functions, classes, and files describe their role.

Data and errors:

- user input is validated,
- file operations check read and write errors,
- an empty data set is handled predictably,
- boundary cases are described or tested,
- error messages help the user correct the input.

Tests and verification:

- the project has automated tests or manual verification scenarios,
- there is one valid-data scenario,
- there is one invalid-data scenario,
- there is one boundary scenario, such as an empty list, zero, or missing file,
- the student can repeat the scenarios during review.

Documentation and demo:

- `README.md` describes the project goal,
- `README.md` separates the minimum version from extensions,
- limitations or known gaps are described honestly,
- the student can point to the most important functions, classes, or modules,
- the student can explain what could be added in the next version.

## Grading Rubric

Use this simple 100-point rubric:

| Area | Points | What is evaluated |
| --- | ---: | --- |
| Minimum functionality | 30 | All minimum requirements work. |
| Technical correctness | 20 | The project compiles with warnings enabled, avoids committed build artifacts, and handles invalid input. |
| Code organization | 20 | Code is split into functions, classes, and files that match the problem. Names are clear. |
| Tests or verification scenarios | 15 | The author can show valid, invalid, and boundary cases. |
| Documentation | 10 | `README.md` explains build, run, structure, limitations, and usage. |
| Extensions | 5 | Useful additions are implemented without breaking the minimum version. |

Review should start with the minimum version. If the minimum version does not
compile or run, extensions should not compensate for it.

## Technical Review Questions

During project review, be ready to explain:

- where the program reads data,
- where the program writes data,
- where the most important logic is located,
- how user errors are handled,
- why you chose specific containers or classes,
- what you would change in the next version.

## Suggested Project Topics

Logger:

- writes messages to a text file,
- supports levels such as info, warning, and error,
- practices files, validation, and timestamps.

Calculator:

- evaluates arithmetic expressions,
- can start with simple operations,
- can later add history, parentheses, or functions.

CSV parser:

- reads rows from a text file,
- validates column counts,
- reports malformed input.

Vehicle database:

- stores vehicles in a collection,
- supports add, list, search, and save,
- practices classes and file storage.

Task manager:

- stores tasks with status and priority,
- supports add, complete, filter, and save,
- practices STL, classes, and validation.

ATM simulator:

- models account balance and operations,
- validates withdrawals and deposits,
- practices state, menu flow, and tests.

Games:

- start with console or simple rendering,
- keep the model of the game separate from drawing,
- define clear winning, losing, and restart rules.

## Final Advice

Build projects in small steps:

1. Create the directory structure.
2. Add a minimal README with build and run commands.
3. Write the smallest program that compiles.
4. Add the data model or first class.
5. Implement one minimum feature.
6. Run it and write one verification scenario.
7. Add the next feature only after the previous one works.

This approach makes progress visible and keeps the project review concrete.
