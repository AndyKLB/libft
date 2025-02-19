# Minishell

Minishell est une implémentation simplifiée d'un shell Unix, inspiré de Bash. Ce projet permet de comprendre le fonctionnement interne d'un interpréteur de commandes en C.

## Fonctionnalités

- Exécution de commandes Unix simples et avec arguments
- Gestion des variables d'environnement
- Opérateurs de redirection (`>`, `>>`, `<`)
- Pipes (`|`)
- Gestion des signaux (`Ctrl+C`, `Ctrl+D`, `Ctrl+\`)
- Builtins (`echo`, `cd`, `pwd`, `export`, `unset`, `env`, `exit`)

## Compilation et Exécution

```sh
make
./minishell
```

## Utilisation

```sh
$ ./minishell
minishell$ ls -l | grep minishell > output.txt
minishell$ echo "Hello, world!"
minishell$ exit
```

## Auteurs

Projet réalisé dans le cadre de l'école 42.

wzeraig et ankammer

