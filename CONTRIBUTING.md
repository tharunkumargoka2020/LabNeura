# Contributing to LabNeura

Thank you for your interest in contributing to LabNeura! We welcome contributions in various forms, including bug reports, feature requests, code, documentation, and more. Please follow the guidelines below to ensure a smooth contribution process.

## Table of Contents

- [Code of Conduct](#code-of-conduct)
- [How to Contribute](#how-to-contribute)
- [Reporting Bugs](#reporting-bugs)
- [Suggesting Enhancements](#suggesting-enhancements)
- [Submitting Pull Requests](#submitting-pull-requests)
- [Style Guidelines](#style-guidelines)
- [Local Development Setup](#local-development-setup)
- [Testing Guidelines](#testing-guidelines)
- [Branch Naming Conventions](#branch-naming-conventions)
- [Commit Message Guidelines](#commit-message-guidelines)
- [Review Process](#review-process)
- [Communication Channels](#communication-channels)
- [License Information](#license-information)

## Code of Conduct

By participating in this project, you agree to abide by our [Code of Conduct](CODE_OF_CONDUCT.md). Please read it to understand the standards of behavior we expect from contributors.

## How to Contribute

1. **Fork the repository**: Click the "Fork" button at the top right corner of this repository to create your own copy.
2. **Clone your fork**: Clone your forked repository to your local machine.
    ```sh
    git clone https://github.com/your-username/labneura.git
    ```
3. **Create a new branch**: Create a new branch for your contribution.
    ```sh
    git checkout -b feature-or-bugfix-name
    ```
4. **Make your changes**: Make your changes in your local repository.
5. **Commit your changes**: Commit your changes with a descriptive commit message.
    ```sh
    git commit -m "Description of the changes"
    ```
6. **Push to your fork**: Push your changes to your forked repository.
    ```sh
    git push origin feature-or-bugfix-name
    ```
7. **Create a Pull Request**: Open a pull request from your forked repository to the main repository.

## Reporting Bugs

If you find a bug, please report it by [opening an issue](https://github.com/tharungoka/labneura/issues). Include as much detail as possible to help us diagnose and fix the issue quickly. Please follow the template provided when creating an issue.

## Suggesting Enhancements

If you have a feature request or enhancement idea, please [open an issue](https://github.com/tharungoka/labneura/issues) and describe the enhancement you would like to see. Explain why this feature would be useful and how it should work.

## Submitting Pull Requests

1. Ensure your changes pass all tests and meet the project's coding standards.
2. Include tests for your changes, if applicable.
3. Update the documentation to reflect your changes, if necessary.
4. When submitting a pull request, provide a clear and detailed description of the changes. Link to any relevant issues or feature requests.

## Style Guidelines

### Python

- Follow the [PEP 8](https://www.python.org/dev/peps/pep-0008/) style guide.
- Use meaningful variable and function names.
- Write docstrings for all public modules, functions, classes, and methods.

### C++

- Follow the [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html).
- Use meaningful variable and function names.
- Write comments to explain complex code and algorithms.

### General

- Keep your code clean and well-organized.
- Write unit tests for your code.
- Ensure your code is efficient and performs well.

## Local Development Setup

1. **Clone your fork**: Clone the repository to your local machine.
    ```sh
    git clone https://github.com/your-username/labneura.git
    cd labneura
    ```
2. **Install dependencies**: Install the necessary dependencies for the project.
    ```sh
    pip install -r requirements.txt
    ```

## Testing Guidelines

1. **Run tests**: Use `pytest` to run the tests.
    ```sh
    pytest
    ```
2. **Add tests**: When you add new features or fix bugs, include corresponding tests.

## Branch Naming Conventions

- `feature/description`: For new features.
- `bugfix/description`: For bug fixes.
- `hotfix/description`: For urgent fixes.

## Commit Message Guidelines

- Use the present tense ("Add feature" not "Added feature").
- Use the imperative mood ("Move cursor to..." not "Moves cursor to...").
- Limit the first line to 72 characters or less.
- Reference issues and pull requests liberally after the first line.

## Review Process

1. After submitting a pull request, request a review from one of the maintainers.
2. The reviewer will check the code for quality, correctness, and adherence to guidelines.
3. Address any feedback and update your pull request as needed.

## Communication Channels

- **GitHub Issues**: For discussing bugs and feature requests.
- **Email**: You can reach out to the maintainers via email for more direct communication.

## License Information

By contributing to LabNeura, you agree that your contributions will be licensed under the [Apache License 2.0](LICENSE).

We appreciate your contributions and look forward to collaborating with you to improve LabNeura!

Thank you for contributing!

The LabNeura Team
