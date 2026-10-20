Note: This format has not been fully formalized and changes may occur at any time

This document defines version 0

# Definitions

- The coordinate (0, 0) is defined to be the center of the screen by default. This is also (0, 0) in world space
    - This will generally be the "root node" of a model
- Numbers are in little-endian, meaning the least significant bit is near the beginning.
- Strings are utf-8 encoded and length-prefixed in bytes.
    - This means that a string has the format `<length><string>`
- The size of numbers are generally 2, 4, and 8 bytes.
    - 2 bytes is only used for the file version. If this format ever goes past version 65,535 then please kill this project lol.
    - 4 bytes are used for all numbers including integers and floats.
    - 8 bytes are used for file offsets.

# VTube Project File Format

## Overview

The `.vtp` file format defines a VTubasic project for the VTubasic Editor.

# VTube Mesh File Format

## Overview

The `.vtm` file format is a compact binary format for the VTubasic Runtime.

All binary will be expressed in hexadecimal.

## File Structure

The overall file structure is layed out like the following diagram:

```
|-------------------------|
| File Header             |
| ----------------------- |
| Metadata Tags           |
| ----------------------- |
| Texture Reference Data  |
| ----------------------- |
| Parameter Data          |
| ----------------------- |
| Mesh Data               |
| ----------------------- |
| Deformer Data           |
| ----------------------- |
```

The file header defines various aspects about the *entire* file. Each `Data` section has a header for each object defined in it. For example:

```
|---------|
| Header  |
| ------- |
| Data    |
| ------- |
| Header  |
| ------- |
| Data    |
| ------- |
| ...     |
| ------- |
```

The overall file header will determine how many headers its expecting for each section. If a section (parameter, mesh, deformer) has an incorrect amount of header/data segments this means that the file is ,malformed. 

## Headers

### Main File Header

The `.vtm` file header starts with the magic bytes:

```
76 74 75 62 61 73 69 63
```

These are the string "vtubasic" in ascii. After this, the next two bytes represent the version of the format. For example, VTubasic version 1 would start with the following header:

```
76 74 75 62 61 73 69 63 00 01
|       vtubasic       |ver 1|
```

As you can probably guess from the example above (and if you read the [definitions section](#definitions)), numbers are in little-endian, meaning the least significant bit is near the beginning.

The rest of the file header defines data about the whole file:

| Name                | Size (Bytes) | Description                                                     |
| :------------------ | :----------- | :-------------------------------------------------------------- |
| Magic  Bytes        | 8            | Always the same                                                 |
| Version             | 2            | File Format Version                                             |
| File Flags          | 4            | Optional bit flags for certain toggleable features              |
| Metadata Tag Count  | 4            | How many metadata tags are defined in the file                  |
| Texture Count       | 4            | How many Textures are defined in the file                       |
| Parameter Count     | 4            | How many Input Parameters are defined in the file               |
| Mesh Count          | 4            | How many 2D meshes (also called layers) are defined in the file |
| Deformer Count      | 4            | How many deformers are defined in the file                      |
| Metadata Tag Offset | 8            | Where in the file the metadata tag definitions start            |
| Texture Offset      | 8            | Where in the file the texture definitions start                 |
| Parameter Offset    | 8            | Where in the file the parameter definitions start               |
| Mesh Offset         | 8            | Where in the file the mesh definitions start                    |
| Deformer Offset     | 8            | Where in the file the deformer definitions start                |

## Data Sections

A data section is a group of data segments. There are five main data segments for a `.vtm` file:

1. Metadata Tags
2. Textures
3. Parameters
4. Meshes
5. Deformers

Each segment has its own header and data definitions. 

### Metadata Tags

Metadata tags are not standardized. These can be used for anything that any program might need like copyright information, timestamps, etc.

#### Data

Tags have a name and a value. These are user-defined strings.

| Name             | Size (Bytes) | Description                    |
| :--------------- | :----------- | :----------------------------- |
| Tag Name Length  | 4            | Length of the tag name string  |
| Tag Name         | \<variable\> | Tag name string                |
| Tag Value Length | 4            | Length of the tag value string |
| Tag value        | \<variable\> | Tag value string               |


### Textures

INCOMPLETE

<!-- TODO -->

### Parameters

A parameter is a 1-dimensional number input. These are the simplest of the data types and are used as inputs for deformers. A deformer may use multiple parameters at once. 

#### Header

Parameters headers have the following structure:

| Name                | Size (Bytes) | Description                                                                                     |
| :------------------ | :----------- | :---------------------------------------------------------------------------------------------- |
| Parameter Name Size | 4            | Size in bytes of the string name of the parameter                                               |
| Parameter Name      | \<Variable\> | The name of the parameter. This is used as the key for an external output. This must be unique. |

#### Data

Parameter data has the following structure:

| Name                    | Size (Bytes) | Description                                                           |
| :---------------------- | :----------- | :-------------------------------------------------------------------- |
| Minimum Parameter Value | 4            | 32-bit float that represents the minimum value of the parameter input |
| Maximum Parameter Value | 4            | 32-bit float that represents the maximum value of the parameter input |

This is the simplest of the data types as it does not have a variable data size.

### Meshes

Meshes define what is actually drawn to the screen. A mesh definition will take on the following structure:

```
|-----------|
| Header    |
| --------- |
| Vertices  |
| -------   |
| Triangles |
| -------   |
```

#### Header

| Name           | Size (Bytes) | Description                                                                                     |
| :------------- | :----------- | :---------------------------------------------------------------------------------------------- |
| Texture Index  | 4            | Texture this mesh binds to. The index is determined by the definition order earlier in the file |
| Draw Order     | 4            | Defines where in the order this mesh is drawn by default                                        |
| Vertex Count   | 4            | Amount of vertices defined for the mesh                                                         |
| Triangle Count | 4            | Amount of triangles defined for the mesh                                                        |

#### Data

##### Vertex

A vertex is defined by its two-dimensional Euclidean coordinates and UV coordinates. Each 4 bytes is a number that is dumped in the struct.

```
| x pos | y pos | u pos | v pos |
```

- The x and y positions are 32-bit floats in world coordinates
- The u and v positions are 32-bit unsigned integers in pixels
    - For textures, (0, 0) is defined as the top-left pixel. 

##### Triangle

A triangle is defined by 3 vertices in counter-clockwise order. If you remember the right-hand rule in physics, this is the reason why it is this way. The normal of each triangle is "out" of the screen.

Each value is a 32-bit byte unsigned integer which determines the *index* of the triangle defined in the previous data segment. 

```
| Vertex 1 Index | Vertex 2 Index | Vertex31 Index |
```

Vertices are 0-indexed. This means a single triangle made up of the first three vertices would be defined as shown:

```
00 01 02
```