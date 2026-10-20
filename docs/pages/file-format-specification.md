Note: This format has not been fully formalized and changes may occur at any time

This document defines version 0

# VTube Project File Format

## Overview

The `.vtp` file format defines a VTubasic project for the VTubasic Editor.

# VTube Mesh File Format

## Overview

The `.vtm` file format is a compact binary format for the VTubasic Runtime.

All binary will be expressed in hexadecimal.

## Headers

The `.vtm` file header starts with the magic bytes:

```
76 74 75 62 61 73 69 63
```

These are the string "vtubasic" in ascii. After this, the next two bytes represent the version of the format. For example, VTubasic version 0 would start with

```
76 74 75 62 61 73 69 63 00 00
|       vtubasic       |ver 0|
```

The rest of the file header defines data about the whole file:

| Name            | Size (Bytes) | Description                                                     |
| :-------------- | :----------- | :-------------------------------------------------------------- |
| Magic  Bytes    | 8            | Always the same                                                 |
| Version         | 2            | File Format Version                                             |
| Parameter Count | 4            | How many Input Parameters are defined in the file               |
| Mesh Count      | 4            | How many 2D meshes (also called layers) are defined in the file |
| Deformer Count      | 4            | How many deformers are defined in the file |
| File Flags      | 4            | Optional bit flags for certain toggleable features                                                  |

## Data
